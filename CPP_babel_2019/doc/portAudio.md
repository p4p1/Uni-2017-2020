# Port Audio doc:

## Prototype:
```
bool checkError() const;	// checks for an error, returns true if an error is found
void displayError() const;	// Displays the found error
void startAudio() const;	// Starts the audio stream
void playAudio() const;		// Plays the audio stream
void stopAudio() const;		// Stops the ausio stream
```

## How to use:

To use you need to create the class:
```
portAudio audio(&callbackFunction);
```
To start the sound you need to call the startAudio.
```
audio.startAudio();
```
When you have your loop for the call, it should look like this you will need
to play the audio:
```
while (in_call) {
	// things to do...
	audio.playAudio();
}
```
when finished please call the stop audio and then the destructor
```
audio.stopAudio();
```

Example:
```
audio.startAudio()
while (in_call) {
	// things to do...
	audio.playAudio();
}
audio.stopAudio();


## WARNING: What is a callback fucntion?
The callback function the function that plays the sound, it will take the encoded
sound and then return it to port audio so it can play it <3