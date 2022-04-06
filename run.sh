mkdir -p out \
    && g++ ./src/*.cpp -o ./out/app \
    && cd out \
    && ./app \
    || cd ..
