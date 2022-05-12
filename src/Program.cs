using Silk.NET.Input;
using Silk.NET.Maths;
using Silk.NET.Windowing;


namespace Walpy.RandomLeftGame
{

    internal class Program
    {

        private static IWindow window;

        static void Main(string[] args)
        {
            // set window options;
            var options = WindowOptions.DefaultVulkan;
            options.Size = new Vector2D<int>(270, 270);
            options.Title = "walpy://game --type random --direction left";

            // create window;
            window = Window.Create(options);

            // add window events;
            window.Load += OnLoad;

            // run window;
            window.Run();
        }

        private static void OnLoad()
        {
            IInputContext context = window.CreateInput();
            for (int i = 0; i < context.Keyboards.Count; i++)
            {
                //context.Keyboards[i].KeyDown += OnKeyDown;
                context.Keyboards[i].KeyUp += OnKeyUp;
            }
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
