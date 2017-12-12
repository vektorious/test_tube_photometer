
module example003()
{
	difference() {
		union() {
			translate([-1.5, -5, 0])
				cube([35, 40,  75], center = false);	

			
		}
		union() {
            translate([0.8, -2.3, 0])
				cube([30.4, 35.4,  75], center = false);
            translate([30.1-11-0.1 , 31, 47])
				cube([1.2, 5, 28], center = false);
            translate([0.9+11+0.1, 31, 47])
				cube([1.2, 5, 28], center = false);
            translate([16, -3, 33+28])
                cube([1, 5, 28], center = true);
}
	}
}

example003();

