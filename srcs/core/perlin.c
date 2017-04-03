/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:10:58 by telain            #+#    #+#             */
/*   Updated: 2017/04/03 11:15:03 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#define FADE(x)			(x * x * x * (x * (x * 6 - 15)+ 10))
#define LERP(x, y, z)	(y + x * (z - y))
#define X_FLOOR			n[0]
#define Y_FLOOR			n[1]
#define Z_FLOOR			n[2]
#define P_A				n[3]
#define P_AA			n[4]
#define P_AB			n[5]
#define P_B				n[6]
#define P_BA			n[7]
#define P_BB			n[8]
#define P_U				d[0]
#define P_V				d[1]
#define P_W				d[2]

static int
permutation[] = { 151,160,137,91,90,15,
	131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
	190,6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
	88,237,149,56,87,174,20,125,136,171,168,68,175,74,165,71,134,139,48,27,166,
	77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
	102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208,89,18,169,200,196,
	135,130,116,188,159,86,164,100,109,198,173,186,3,64,52,217,226,250,124,123,
	5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
	23,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167,43,172,9,
	129,22,39,253,19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
	251,34,242,193,238,210,144,12,191,179,162,241,81,51,145,235,249,14,239,107,
	49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127,4,150,254,
	138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180
};

// static double fade(double t)
// {
// 	return (t * t * t * (t * (t * 6 - 15) + 10));
// }

// static double lerp(double t, double a, double b)
// {
// 	return (a + t * (b - a));
// }

static double	grad(int hash, double x, double y, double z)
{
	int h = hash & 15;
	// CONVERT LO 4 BITS OF HASH CODE
	double u = h < 8 || h == 12 || h == 13 ? x : y, // INTO 12 GRADIENT DIRECTIONS.
	v = h < 4 || h == 12 || h == 13 ? y : z;
	return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}

void			init_perlin(int perlin[512])
{
	int i;


	i = 0;
	while (i < 256)
	{
		perlin[256+i] = permutation[i];
		perlin[i] = permutation[i];
		++i;
	}
}

static void		sub_perlin(int p[512], int n[9])
{
	P_A = p[X_FLOOR] + Y_FLOOR;
	P_AA = p[P_A] + Z_FLOOR;
	P_AB = p[P_A + 1] + Z_FLOOR;
	P_B = p[X_FLOOR + 1] + Y_FLOOR,
	P_BA = p[P_B] + Z_FLOOR,
	P_BB = p[P_B + 1] + Z_FLOOR;
}

float			perlin(float x, float y, float z)
{
	int		perlin[512];
	int		n[9];
	float	d[3];

	init_perlin(perlin);
	X_FLOOR = (int)floor(x) & 255;
	Y_FLOOR = (int)floor(y) & 255;
	Z_FLOOR = (int)floor(z) & 255;
	x -= floor(x);
	y -= floor(y);
	z -= floor(z);
	P_U = FADE(x);
	P_V = FADE(y);
	P_W = FADE(z);
	sub_perlin(perlin, n);
	return (LERP(P_W, LERP(P_V, LERP(P_U, grad(perlin[P_AA], x, y, z),		// AND ADD
	grad(perlin[P_BA], x - 1, y, z)),							// BLENDED
	LERP(P_U, grad(perlin[P_AB], x, y - 1, z),					// RESULTS
	grad(perlin[P_BB], x - 1, y - 1, z))),						// FROM 8
	LERP(P_V, LERP(P_U, grad(perlin[P_AA + 1], x, y, z - 1),			// CORNERS
	grad(perlin[P_BA + 1], x - 1, y, z - 1)),						// OF CUBE
	LERP(P_U, grad(perlin[P_AB + 1], x, y - 1, z - 1 ),
	grad(perlin[P_BB + 1], x - 1, y - 1, z - 1 )))));
}
