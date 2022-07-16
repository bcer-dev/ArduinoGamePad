CC=pio

build:
	$(CC) run

upload:
	$(CC) run --target upload

clean:
	$(CC) run --target clean