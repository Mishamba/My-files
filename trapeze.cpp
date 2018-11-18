#include <iostream>
#include <math.h>

class trapeze
{
    private:
        point p1,
  	   	   	p2,
       		p3,
        	p4;
    public:
        trapeze()
        {
            p1(0,0);
            p2(0,0);
            p3(0,0);
            p4(0,0);
        }

        trapeze(int t_x1, int t_y1, int t_x2, int t_y2, int t_x3, int t_y3, int t_x4, int t_y4)
        {
            p1(t_x1, t_y1);
            p2(t_x2, t_y2);
            p3(t_x3, t_y3);
            p4(t_x4, t_y4);
        }

        bool equi_trap(trapeze trap)
        {
            if((fabs(trap.p2.x - trap.p1.x) == fabs(trap.p4.x - trap.p3.x)) &&
                fabs(trap.p2.y - trap.p1.y) == fabs(trap.p4.y - trap.p3.y))
                return true;
            else
                return false;
        }

		int square(trapeze trap)
		{
			int* legs = leg_length(trap);
			int res;
			if(equi_trap(trap))
			{
				int half,
					height;
				half = (legs[0] - legs[2])/2;
				height = sqrt(pow(leg[1], 2) - pow(half, 2));
				res = ((legs[2] + half) * height);
				return res;
			}
		}

		int* leg_length(trapeze trap)
        {
            if((trap.p1.y == trap.p4.y) && (trap.p2.y == trap.p3.y)) //finish another scenario
            {
                int* legs = new int[4];
                legs[0] = fabs(trap.p1.x - trap.p4.x);
                legs[1] = sqrt(pow((trap.p2.y - trap.p1.y), 2) + pow((trap.p1.x - trap.p2.x), 2));
                legs[2] = fabs(trap.p2.x - trap.p3.x);
                legs[3] = fabs(pow((trap.p3.y - trap.p4.y), 2) + pow((trap.p3.x - trap.p4.x), 2));
                return legs;
            }
        }


		int perimetr(trapeze trap)
		{
			int* legs = leg_length(trap);
			int res;
			for(int i=0;i<4;i++)
			{
				res+=legs[i];
			}
			return res;
		}

        ~trapeze() //finish destructor
        {}
};

int medium_square(trapeze* trap)
{
	int* sqre = new int[???];
	int res;
	for(int i=0;i<(???);i++)
	{
		sqre[i] = square(trap[i]);
	}

	for(int i=0;i<(???);i++)
	{
		res += sqre[i];
	}
	res /= (???);
	return res;
}

struct point
{
    int x, y;
    point(int t_x, int t_y)
    {
        x = t_x;
        y = t_y;
    }
};

int main()
{

}
