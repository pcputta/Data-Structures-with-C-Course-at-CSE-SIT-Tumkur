figure_t get_figure_dimensions(void);
figure_t compute_area(figure_t object);
figure_t compute_perim(figure_t object);
void print_figure(figure_t object);
int main(void)
{
	figure_t onefig;
	printf("Area and Perimeter Computation Program\n");
	for(onefig = get_figure_dimensions();
	onefig.shape != 'Q';
	onefig = get_figure_dimensions()) {
		onefig = compute_area(onefig);
		onefig = compute_perim(onefig);
		print_figure(onefig);
	}
	return (0);
}

/*
* Prompts for and stores the dimension data necessary to compute a
* figure's area and perimeter. Figure returned contains a 'Q' in the
* shape component when signaling end of data.
*/

figure_t get_figure_dimensions(void)
{
	figure_t object;
	printf("Enter a letter to indicate the object shape or Q to quit.\n");
	printf("C (circle), R (rectangle), or S (square)> ");
	object.shape = getchar();
	switch (object.shape) 
	{
		case 'C':
		case 'c':
		printf("Enter radius> ");
		scanf("%lf", &object.fig.circle.radius);
		break;
		case 'R':
		case 'r':
		printf("Enter height> ");
		scanf("%lf", &object.fig.rectangle.height);
		printf("Enter width> ");
		scanf("%lf", &object.fig.rectangle.width);
		break;
		case 'S':
		case 's':
		printf("Enter length of a side> ");
		scanf("%lf", &object.fig.square.side);
		break;
		default: /* Error is treated as a QUIT */
		object.shape = 'Q';
	}
	return (object);
}


/*
* Computes the area of a figure given relevant dimensions. Returns
* figure with area component filled.
* Pre: value of shape component is one of these letters: CcRrSs
* necessary dimension components have values
*/

figure_t compute_area(figure_t object)
{
	switch (object.shape) 
	{
		case 'C':
		case 'c':
				object.fig.circle.area = PI * object.fig.circle.radius * object.fig.circle.radius;
				break;

		case 'R':
		case 'r':
				object.fig.rectangle.area = object.fig.rectangle.height * object.fig.rectangle.width;
				break;

		case 'S':
		case 's':
				object.fig.square.area = object.fig.square.side * object.fig.square.side;
				break;

		default:
				printf("Error in shape code detected in compute_area\n");
	}
	return (object);
}
