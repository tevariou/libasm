FROM ubuntu:latest
RUN apt update && apt install -y build-essential
WORKDIR /project
COPY . /project
RUN make test
ENTRYPOINT ["./test_libasm"]
