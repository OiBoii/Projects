# Pedometer

This was a fun little project for me! I enjoy prototyping, but never had the chance to try and make a wearable device. The algorithm for the code and the schematics were straight forward, so I spent my time focusing on the design aspect. I am not currently home, and don’t have any old clothes to spare, so I decided to make this an integrated device, rather than an embedded one. The challenge was trying to keep it stable. For that reason, I decided to go for the old fashioned design of the clip-on pedometer.

<img src="ped-plan.jpg" width=500px>

Since I wanted to save the Flora sensor for other projects in the class, I took a small perfboard and soldered components I had available to an Arduino Pro Micro. I chose the Pro Micro because I had it readily available from a previous project and it’s small in size which was perfect for this purpose. None of the components I used were designed with the intention of being integrated into clothing, but since all of them were relatively compact - I had no issue fitting them into a small pocket I stitched together from synthetic fabric scraps. I attached a string to the back of the pocket and knotted it a few times to make it thicker. I tightened it around my belt, and made sure it was snug. 

<img src="ped-schematic.jpg" width=500px>

The first trial wasn’t great because I initially designed the code thinking the device was going to be around my wrist. I adjusted the sensitivity of the algorithm and after a little bit of trial and error an acceptable balance and was pretty satisfied with the results. The reason I wanted the device to be on my hips rather than the wrist was because it gave me access to my pockets, which allowed me to draw power directly from a power bank without any trouble. Ideally, I would have integrated a small lithium battery into the circuit, but that worked well enough for the purposes of this demonstration.

Overall, I enjoyed the process, refreshed my soldering skills and learned a bit about stitching!

<img src="ped-prototype.jpg" width=500px>

**The Code:** [OiBoi!](https://github.com/OiBoii/Projects/edit/main/Pedometer/pedometer.ino)
