using Silk.NET.Input;
using Silk.NET.Maths;
using Silk.NET.OpenGL;
using Silk.NET.Windowing;

namespace Walpy.RandomLeftGame
{

    internal class Program
    {

        private static IWindow window;
        private static GL gl;

        private static uint vertexArray;
        private static uint vertexBuffer;
        private static uint elementBuffer;
        private static uint shader;

        private static readonly float[] vertices =
        {
            0.5f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            -0.5f, 0.5f, 0.5f,
        };

        private static readonly uint[] indices =
        {
            0, 1, 3,
            1, 2, 3
        };

        private static readonly string vertexShaderSource = @"
            #version 330 core
            layout (location = 0) in vec4 vPos;

            void main()
            {
                gl_Position = vec4(vPos.x, vPos.y, vPos.z, 1.0);
            }
        ";

        private static readonly string fragmentShaderSource = @"
            #version 330 core
            out vec4 FragColor;

            void main()
            {
                FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
            }
        ";

        static void Main(string[] args)
        {
            // set window options;
            var options = WindowOptions.Default;
            options.Size = new Vector2D<int>(270, 270);
            options.Title = "walpy://game --type random --direction left";

            // create window;
            window = Window.Create(options);

            // add window events;
            window.Load += OnLoad;
            window.Render += OnRender;
            window.Closing += OnClose;

            // run window;
            window.Run();
        }

        private static unsafe void OnLoad()
        {
            IInputContext context = window.CreateInput();
            for (int i = 0; i < context.Keyboards.Count; i++)
            {
                context.Keyboards[i].KeyDown += OnKeyDown;
                context.Keyboards[i].KeyUp += OnKeyUp;
            }

            gl = GL.GetApi(window);

            vertexArray = gl.GenVertexArray();
            gl.BindVertexArray(vertexArray);

            vertexBuffer = gl.GenBuffer();
            gl.BindBuffer(BufferTargetARB.ArrayBuffer, vertexBuffer);
            fixed (void* v = &vertices[0])
            {
                gl.BufferData(
                    BufferTargetARB.ArrayBuffer,
                    (nuint)(vertices.Length * sizeof(uint)),
                    v,
                    BufferUsageARB.StaticDraw
                );
            }

            elementBuffer = gl.GenBuffer();
            gl.BindBuffer(BufferTargetARB.ElementArrayBuffer, elementBuffer);
            fixed (void* i = &indices[0])
            {
                gl.BufferData(
                    BufferTargetARB.ElementArrayBuffer,
                    (nuint)(indices.Length * sizeof(uint)),
                    i,
                    BufferUsageARB.StaticDraw
                );
            }

            uint vertexShader = gl.CreateShader(ShaderType.VertexShader);
            gl.ShaderSource(vertexShader, vertexShaderSource);
            gl.CompileShader(vertexShader);

            string infoLog = gl.GetShaderInfoLog(vertexShader);
            if (!string.IsNullOrEmpty(infoLog))
            {
                Console.WriteLine($"Error compile {nameof(vertexShaderSource)}, cause: {infoLog}");
            }

            uint fragmentShader = gl.CreateShader(ShaderType.FragmentShader);
            gl.ShaderSource(fragmentShader, fragmentShaderSource);
            gl.CompileShader(fragmentShader);

            infoLog = gl.GetShaderInfoLog(fragmentShader);
            if (!string.IsNullOrEmpty(infoLog))
            {
                Console.WriteLine($"Error compile {nameof(fragmentShaderSource)}, cause: {infoLog}");
            }

            shader = gl.CreateProgram();
            gl.AttachShader(shader, vertexShader);
            gl.AttachShader(shader, fragmentShader);
            gl.LinkProgram(shader);

            gl.GetProgram(shader, GLEnum.LinkStatus, out var status);
            if (status == 0)
            {
                Console.WriteLine($"Error linking hader {gl.GetProgramInfoLog(shader)}");
            }

            gl.DetachShader(shader, vertexShader);
            gl.DetachShader(shader, fragmentShader);
            gl.DeleteShader(vertexShader);
            gl.DeleteShader(fragmentShader);

            gl.VertexAttribPointer(
                0,
                3,
                VertexAttribPointerType.Float,
                false,
                3 * sizeof(float),
                null);
            gl.EnableVertexAttribArray(0);
        }

        private static unsafe void OnRender(double obj)
        {
            gl.Clear((uint)ClearBufferMask.ColorBufferBit);

            gl.BindVertexArray(vertexArray);
            gl.UseProgram(shader);

            gl.DrawElements(
                PrimitiveType.Triangles,
                (uint)indices.Length,
                DrawElementsType.UnsignedInt,
                null
            );
        }

        private static void OnClose()
        {
            gl.DeleteBuffer(vertexBuffer);
            gl.DeleteBuffer(elementBuffer);
            gl.DeleteVertexArray(vertexArray);
            gl.DeleteProgram(shader);
        }

        private static void OnKeyDown(IKeyboard keyboard, Key key, int arg)
            => OnKeyStatusChange(true, keyboard, key, arg);

        private static void OnKeyUp(IKeyboard keyboard, Key key, int arg)
            => OnKeyStatusChange(false, keyboard, key, arg);

        private static void OnKeyStatusChange(bool isDown, IKeyboard keyboard, Key key, int arg)
        {
            Console.WriteLine($"key {(int)key} is {(isDown ? "down" : "up")} on keyboard#{keyboard.Index}; int arg is {arg}");
            if (key == Key.Escape && isDown == true)
            {
                window.Close();
            }
        }
    }

}
