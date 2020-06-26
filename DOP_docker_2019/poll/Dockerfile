FROM python:3

WORKDIR /app
COPY requirements.txt /app
COPY app.py /app
COPY templates /app/templates
COPY static /app/static

RUN pip install -r requirements.txt

CMD ["flask", "run", "--host=0.0.0.0", "--port=80"]
