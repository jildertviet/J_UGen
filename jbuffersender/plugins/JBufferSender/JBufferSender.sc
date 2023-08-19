JBufferSender : JEventS {
	*kr { |
		bufnum=0,
		trigger=0,
		targetID = 0,
		subID = 0
		|
		^this.multiNew('control',
		bufnum,
		trigger,
		if(targetID == 1, 1, Float.from32Bits(targetID)),
		subID
		);
	}
}
