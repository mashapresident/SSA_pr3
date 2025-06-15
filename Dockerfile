FROM ubuntu:22.04

RUN apt update && \
    apt install -y linux-tools-common linux-tools-generic build-essential && \
    apt install -y linux-tools-6.8.0-60-generic && \
    apt install sudo && \
    sudo -i


CMD ["bash"]
