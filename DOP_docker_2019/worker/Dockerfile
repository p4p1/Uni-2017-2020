FROM maven:3.5-jdk-8-alpine AS builder

WORKDIR /worker

COPY pom.xml /worker
COPY src /worker/src

RUN mvn dependency:resolve
RUN mvn package

FROM openjdk:8-jre-alpine

WORKDIR /worker
COPY --from=builder worker/target/worker-jar-with-dependencies.jar .

CMD ["java", "-jar", "worker-jar-with-dependencies.jar"]
