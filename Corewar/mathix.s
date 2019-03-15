.name "mathix"
.comment "    __  ______ ________ _______ __
  /  |/  / _ /_  __/ // /  _/ |/_/
 / /|_/ / __ |/ / / _  // /_>  <
/_/  /_/_/ |_/_/ /_//_/___/_/|_|"

first: sti r1, %:live, %1

live: live %42

storage:	ld %589840, r2

attack: st r2, 10
	zjmp %:attack

