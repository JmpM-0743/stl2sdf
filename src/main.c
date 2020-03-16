#include <sys/stat.h>
#include "grid/octree.h"
#include "utils.h"
#include "distance.h"
#include "fractions.h"

void mk_outfilepath(char *outfilepath, char *stlfilename, char *output_dir){
	char *ptr;
	char *ptr2;
	char *buf;
	ptr = strtok(stlfilename, "/");
	while(ptr != NULL) {
		buf = ptr;		
        ptr = strtok(NULL, "/");
    }
	ptr2 = strtok(buf, ".");
	sprintf(outfilepath,"%s%s_sdf.csv", output_dir, ptr2);
}

int main(int argc,char *argv[]){
	char *input_file = argv[1];
	char *output_dir = argv[2];
	int grids = atoi(argv[3]);
	mkdir(output_dir,0755);

	coord *p = input_stl (fopen (input_file, "r"));
	coord min, max;
	bounding_box (p, &min, &max);  
	double maxl = -HUGE;
	foreach_dimension()
		if (max.x - min.x > maxl)
			maxl = max.x - min.x;

	init_grid (grids);
	size (1.2*maxl);
	origin ((max.x + min.x)/2. - L0/2,
		(max.y + min.y)/2. - L0/2,
		(max.z + min.z)/2. - L0/2);
		
	scalar d[];
	distance (d, p);
	
	FILE *fp;
	char outfilepath[256];
	mk_outfilepath(outfilepath,input_file,output_dir);
	if ((fp = fopen(outfilepath, "w")) == NULL) {
		printf("file open error!!\n");
		exit(EXIT_FAILURE);
	}
	fprintf(fp,"x,y,z,distance\n");
	foreach() fprintf(fp,"%lf,%lf,%lf,%lf\n",x,y,z,d[]);
	fclose(fp);
}