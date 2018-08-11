import librosa

# y, s = librosa.load('doom.wav', sr=8000)
# librosa.output.write_wav('down.wav', y, s)
y, s = librosa.load('doom.wav', sr=88200)
librosa.output.write_wav('up.wav', y, s)
