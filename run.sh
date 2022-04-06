mkdir -p out \
    && g++ app.cpp -o ./out/app \
    && cd out \
    && ./app \
    || cd ..
