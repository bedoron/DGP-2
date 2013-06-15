Hello world

* Please use DEBUG to compile.
* Hit B to render BSpline
* To change BETA parameter for BSPline fitting use ALT+<UP>/<DOWN> to increase decrease it

Part 1 + 2:
Default epsilon looks best (0.01)

Part 3:

Beta: 1, Epsilon 0.01 Bunny is missing parts: 
Beta: ~7, Epsilon 0.01 Bunny looks pixelated: http://i.imgur.com/Z5dOkr6.png
Beta: 10, Epsilon 0.01 Starting to lose details in favor of smoothness: http://i.imgur.com/tqrEwjY.png
Beta: 10, Epsilon 0.5 Artifacts appear on bunny: http://i.imgur.com/ywxkion.png

Epsilon should be smallest, Beta should be around 7-10 for the bunny and 1 for the sphere