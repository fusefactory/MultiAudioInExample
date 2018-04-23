# MultiAudioInExample

This is an example that show how read multiple input audio buffer in OpenframeFrameworks. Essentially is is an extension of _audioInputExample_ (included in OF workspace) with the possibility to see more than 2 input audio channels.


### Prerequisites

[OpenframeFrameworks](http://openframeworks.cc/). Tested with OF 0.9.8 with Mac OS 10.13.4 and Windows 10.

### Installing

You can configure number of input channels and the buffer size in ofApp.h
Default values are:
```
const int numChannels = 12;
const int bufferSize = 512;
```

## License

This project is licensed under the Apache License - see the LICENSE.md file for details.
