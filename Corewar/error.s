.name "mathix"
.comment "    __  ______ ________ _______ __
  /  |/  / _ /_  __/ // /  _/ |/_/
 / /|_/ / __ |/ / / _  // /_>  <
/_/  /_/_/ |_/_/ /_//_/___/_/|_|"

first: sti r1, %:live, %1

live: live %1

storage:	ld %4294967295, r2

attack: st r2, -10
	st r3, 17
	ld %0, r5
	zjmp %:attack

	
