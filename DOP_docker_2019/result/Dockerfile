FROM node:12

WORKDIR /japp
COPY package.json /japp
COPY server.js /japp
COPY views /japp/views

RUN npm install

CMD ["npm", "start"]
