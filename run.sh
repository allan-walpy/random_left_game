mkdir -p out \
    && g++ *.cpp -o ./out/app \
    && cd out \
    && ./app \
    || cd ..
