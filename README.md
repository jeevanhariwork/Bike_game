🚴‍♂️ 2D Graphical Bike Riding Simulation

An interactive 2D bike riding simulation built using OpenGL and GLUT in C.
This project demonstrates fundamental computer graphics concepts like transformations, real-time rendering, animations, and user interaction.

📌 Features

🏍️ Animated Bike Simulation – Wheels rotate, bike moves along the road.

🎮 Interactive Controls – Control bike movement with keyboard inputs.

⚙️ Gear System – Increase/decrease speed using gears (1–4).

🖱️ Right-click Menu – Change bike color (Black, Blue, Green, Red).

🤸 Special Maneuver – Perform a wheelie with a single key press.

🌄 Dynamic Environment – Road, grassland, sky, and lamp posts rendered using OpenGL primitives.

⏱️ Smooth Animation – Timer-based rendering for continuous motion.

🕹️ Controls
Key	Action
W / w	Start/Accelerate the bike
S / s	Stop the bike
I / i	Increase gear (max: 4)
D / d	Decrease gear (min: 1)
U / u	Perform a wheelie
Esc	Exit the simulation
Right Mouse Click	Open menu → Change bike color / Exit
🖥️ Installation & Setup
Requirements

C Compiler (GCC, MinGW, etc.)

OpenGL libraries

GLUT/freeGLUT

Steps

Clone this repository:

git clone https://github.com/your-username/bike-simulation.git
cd bike-simulation


Compile the code (example with GCC + freeGLUT):

gcc Bike.c -lGL -lGLU -lglut -lm -o BikeRide


Run the simulation:

./BikeRide

📸 Screenshots

Main Menu & Color Options

Gear Shifting (1 → 4)

Different Bike Colors

Bike Performing a Wheelie

📚 Learning Outcomes

Basics of OpenGL rendering (points, lines, polygons).

Transformations (translation, rotation, scaling).

Keyboard & mouse event handling.

Use of timers for smooth animation.

Structuring interactive graphics applications.

🚀 Future Enhancements

Realistic physics (friction, suspension, inertia).

Advanced visual effects (shadows, reflections).

Day–night cycle & weather effects.

Obstacles and traffic simulation.

Multiplayer support.

VR/Mobile adaptation.

🧑‍💻 Authors

U Jeevan Hari (1DB21CS161)
