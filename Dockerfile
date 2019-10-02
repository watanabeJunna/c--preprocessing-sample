FROM ubuntu:latest

RUN apt-get -y update \
    && apt-get install -y \
    && apt-get -y install clang
