#!/bin/bash

docker build --rm -f "Dockerfile" -t kata:latest .
docker run -v ${PROJECT_BINARY_DIR}:/kata --rm -it kata:latest "ci/build.sh"
