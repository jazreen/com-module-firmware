FROM ubuntu:22.04

# Install apt packages
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        # Your package list here
        build-essential \
        ca-certificates \
        gcc \
        gdb \
        git \
        # libglib2.0-dev \
        # libpcap-dev \
        # libslirp-dev \
        make \
        # wget \
        # zip \
    # Clean up
    && apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/{apt,dpkg,cache,log} /tmp/* /var/tmp/*
ENV DEBIAN_FRONTEND=
