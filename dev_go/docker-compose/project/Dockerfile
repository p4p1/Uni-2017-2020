FROM node:latest
WORKDIR /backend
COPY package.json /backend
COPY main.js /backend

RUN npm install

EXPOSE 8080

CMD ["node", "main.js"]
