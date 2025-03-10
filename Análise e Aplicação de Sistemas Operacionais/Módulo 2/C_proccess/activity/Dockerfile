FROM ubuntu:latest as base

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    init-system-helpers \
    curl \
    gcc \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

COPY ./activity.c /home/activity.c

# CMD ["cd home && gcc activity.c -o activity && ./activity"]

CMD ["tail", "-f", "/dev/null"]
