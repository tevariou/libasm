FROM ubuntu:latest
RUN apt update && apt install -y build-essential nasm
WORKDIR /project
COPY . /project
RUN make build-test
ENTRYPOINT ["./test_libasm"]
