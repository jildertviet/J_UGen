JFunctionTrigger : JEventS{
	*kr { |
id = 0,
trigger = 1,
targetID = 0,
subID = 0,
functionID = 0,
values = #[0,0,0,0,0]
		|
		values = (values ++ [0]).clipExtend(5);
		^this.multiNew('control',
      id,
      trigger,
      targetID,
      subID,
      functionID,
			values[0],
      values[1],
      values[2],
      values[3],
      values[4],
		);
	}
}
