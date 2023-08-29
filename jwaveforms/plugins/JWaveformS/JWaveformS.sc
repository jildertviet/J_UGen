JWaveformS : JEventS {
	checkInputs {
		/* TODO */
		^this.checkValidInputs;
	}
}

JWaveform {
	*kr { |
		id=0,
		loc=#[0,0,0],
		size=#[100, 100, 0],
		direction=#[1,0,0],
		rotation=#[0,0,0],
		speed=1,
		lineWidth=1,
		bMove=0,
		layer=2,
		rgba=#[255,255,255,1.0],
		bFilled=1,
		mode=0,
		busses=#[0,0,0,0,0,0,0,0,0,0],
		buffer=0,
		trigFreq=60
		|
		/* if(busses.size < 10, { */
			/* busses = (busses ++ [0]).clipExtend(10) */
		/* }); */
		^{JWaveformS.kr(
			id: id,
			loc: loc,
			size: size,
			direction: direction,
			rotation: rotation,
			speed: speed,
			lineWidth: lineWidth,
			bMove: bMove,
			layer: layer,
			rgba: rgba,
			bFilled: bFilled,
			mode: mode,
			busses: busses
		);
		JBufferSender.kr(bufnum: buffer, trigger: Impulse.kr(trigFreq), targetID: 1, subID: 0.0);
		1
	}
		/*  */
		/* ^synth; */
		/* ^1; */
	}
}
