#include<stdio.h>

int main()
{
	int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,alph;
	FILE *infile, *outfile;

	if(!(infile = fopen("outalph.txt","r")) || (!(outfile = fopen("alphfreq.txt", "w"))))
	{
		printf("ファイルの読み込みに失敗\n");
		return 1;
	}

	a = b = c = d = e = f = g = h = i = j = k = l = m = n = o = p = q = r = s = t = u = v = w = x = y = z = 0;

	while((alph = fgetc(infile)) != EOF)
	{
		if(alph == 'a')
		{
			a = a + 1;
		} else if(alph == 'b')
		{
			b = b + 1;
		} else if(alph == 'c')
		{
			c = c + 1;
		} else if(alph == 'd')
		{
			d = d + 1;
		} else if(alph == 'e')
		{
			e = e + 1;
		} else if(alph == 'f')
		{
			f = f + 1;
		} else if(alph == 'g')
		{
			g = g + 1;
		} else if(alph == 'h')
		{
			h = h + 1;
		} else if(alph == 'i')
		{
			i = i + 1;
		} else if(alph == 'j')
		{
			j = j + 1;
		} else if(alph == 'k')
		{
			k = k + 1;
		} else if(alph == 'l')
		{
			l = l + 1;
		} else if(alph == 'm')
		{
			m = m + 1;
		} else if(alph == 'n')
		{
			n = n + 1;
		} else if(alph == 'o')
		{
			o = o + 1;
		} else if(alph == 'p')
		{
			p = p + 1;
		} else if(alph == 'q')
		{
			q = q + 1;
		} else if(alph == 'r')
		{
			r = r + 1;
		} else if(alph == 's')
		{
			s = s + 1;
		} else if(alph == 't')
		{
			t = t + 1;
		} else if(alph == 'u')
		{
			u = u + 1;
		} else if(alph == 'v')
		{
			v = v + 1;
		} else if(alph == 'w')
		{
			w = w + 1;
		} else if(alph == 'x')
		{
			x = x + 1;
		} else if(alph == 'y')
		{
			y = y + 1;
		} else if(alph == 'z')
		{
			z = z + 1;
		}
	}

	fprintf(outfile,"%d : a\n", a);
	fprintf(outfile,"%d : b\n", b);
	fprintf(outfile,"%d : c\n", c);
	fprintf(outfile,"%d : d\n", d);
	fprintf(outfile,"%d : e\n", e);
	fprintf(outfile,"%d : f\n", f);
	fprintf(outfile,"%d : g\n", g);
	fprintf(outfile,"%d : h\n", h);
	fprintf(outfile,"%d : i\n", i);
	fprintf(outfile,"%d : j\n", j);
	fprintf(outfile,"%d : k\n", k);
	fprintf(outfile,"%d : l\n", l);
	fprintf(outfile,"%d : m\n", m);
	fprintf(outfile,"%d : n\n", n);
	fprintf(outfile,"%d : o\n", o);
	fprintf(outfile,"%d : p\n", p);
	fprintf(outfile,"%d : q\n", q);
	fprintf(outfile,"%d : r\n", r);
	fprintf(outfile,"%d : s\n", s);
	fprintf(outfile,"%d : t\n", t);
	fprintf(outfile,"%d : u\n", u);
	fprintf(outfile,"%d : v\n", v);
	fprintf(outfile,"%d : w\n", w);
	fprintf(outfile,"%d : x\n", x);
	fprintf(outfile,"%d : y\n", y);
	fprintf(outfile,"%d : z\n", z);


	fclose(outfile);
	fclose(infile);

	return 0;
}

