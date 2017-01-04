static int		print_map(t_point *grid)
{
  t_point *current;

  while (grid)
  {
	  current = grid;
	  while (current)
	  {
		  printf("%3d ", current->z);
		  current = current->right;
	  }
	  printf("\n");
	  grid = grid->down;
  }
  return (1);
}
