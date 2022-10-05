Google Drive link of project: https://drive.google.com/drive/folders/1IrK3VMEWwfCBvxN8tlcFQzr2kbgt7HJ8?usp=sharing

Features implemented:

-Basic features:
	Implemented a parabolic trajectory by increasing the value of vertical velocity every iteration, while maintaining a constant horizontal velocity.
	Bouncing mechanics against all four surfaces of the game window.
	Collision between bubble and bullet, causing both to disappear after collision.
	Collision between bubble and shooter, causing health to drop by one bar.

-Extra features:
	Added a score counter which increases by one on shooting a bubble.
	Added a health counter, which has three green bars to begin with and decreases by one everytime the shooter is hit by a bubble.
	Added a time counter, which keeps ticking down and ends the game when it hits zero. The timer resets for every level with less time than the previous level.
	Implemented five different levels, each of increasing difficulty, wherein the bubbles have greater velocity or greater acceleration or both :)
	Each level has bubbles of different colors, and the user can move up to the next level when he shoots all the bubbles of the current level before the timer runs out.
	On moving up by a level, the shooter gets an extra bar of health.
	The vertical velocity is reset on colliding with the top or bottom to prevent infinite acceleration, which would make the game lag and the ball impossible to hit.
