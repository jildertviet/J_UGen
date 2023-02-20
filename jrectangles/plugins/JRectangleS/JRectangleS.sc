JRectangleS : UGen {
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
		bFilled=1
		|
		^this.multiNew('control',
		id,
		Impulse.kr(120),
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
		layer,
		rgba[0],
		rgba[1],
		rgba[2],
		rgba[3],
		bFilled
		);
	}
	checkInputs {
		^this.checkValidInputs;
	}
}
