JRectangleS : UGen {
	*kr { |
		loc=#[0,0,0],
		size=#[100, 100, 0],
		direction=#[1,0,0],
		rotation=#[0,0,0],
		speed=1,
		lineWidth=1,
		bMove=0,
		layer=2
		|
		^this.multiNew('control',
		Impulse.kr(60),
		loc[0],
		loc[1],
		loc[2],
		size[0],
		size[1],
		size[2],
		direction[0],
		direction[1],
		direction[2],
		rotation[0],
		rotation[1],
		rotation[2],
		speed,
		lineWidth,
		bMove,
		layer
		);
	}
	checkInputs {
		^this.checkValidInputs;
	}
}
