
module example003()
{
	difference() {
		union() {
			translate([-1.5, -5, 0])
				cube([30, 35,  75], center = false);	
			//translate([25, -5, 0])
				//cube([3.5, 10, 65], center = false);	
			//translate([-1.5, 5, 0])
				//cube([3.5, 3.5, 65], center = false);
			//translate([28, 13, 0])
				//cube([2.5, 3.5, 75], center = false);
			
		}
		union() {
			translate([13.5, 15, 5])
				cylinder(h = 100, r = 8.5, center = false, $fn = 100); //tube 
			translate([13.5, 6, 20])
				rotate(90, [1, 0, 0]) cylinder(h = 20, r = 2.5, center = false, $fn = 100); //led
            translate([13.5, -3.1, 20])
				rotate(90, [1, 0, 0]) cylinder(h = 2, r = 3, center = false, $fn = 100); //led
			translate([13.5, 50, 20])
				rotate(90, [1, 0, 0]) cylinder(h = 50, r = 0.5, center = false, $fn = 100); //apature
			translate([13.5, 30, 20])
				cube([6.2, 10, 10], center = true); //sensor
			translate([13.5, 30, 20])
				cube([11, 3.5, 10], center = true); //sensor wires
			//translate([13.5, 30, 96])
				//cube([32, 8, 10], center = true);	 //multiple sensor wire channel
			//translate([13.5, 0, 70])
				//cube([4, 10, 100], center = true);	 //led wires
			//translate([13.5, 0, 96])
				//cube([32, 1, 10], center = true);	 //multiple led wire channel
			//translate([24, 28, -0.5])
				//cube([6, 5, 92], center = false);	
			//translate([-2, -2, -0.5])
				//cube([5, 4, 92], center = false);	
			//translate([-2, 13, -0.5])
				//cube([2.5, 4.5, 110], center = false);	
}
	}
}

example003();

