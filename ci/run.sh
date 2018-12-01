#!/bin/bash

docker build --rm -f "Dockerfile" -t advent-of-code:latest .
docker run -v ${PROJECT_BINARY_DIR}:/src --rm -it advent-of-code:latest "ci/build-and-run.sh"