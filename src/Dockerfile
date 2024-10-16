FROM ubuntu:22.04

RUN apt-get update
RUN apt-get install make build-essential libgtest-dev clang-format valgrind -y

COPY . /s21

WORKDIR /s21

ENTRYPOINT [ "make", "test", "style" ]
