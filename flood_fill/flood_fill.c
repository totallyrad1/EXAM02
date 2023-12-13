  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

void fill(char **tab, t_point size, t_point current, char target, char tofillwith)
{
    if (current.x < 0 || current.x >= size.x || current.y < 0 || current.y >= size.y)
        return;

    if (tab[current.y][current.x] != target)
        return;

    tab[current.y][current.x] = tofillwith;

    // Recur for all connected neighbors
    fill(tab, size, (t_point){current.x - 1, current.y}, target, tofillwith); // Left
    fill(tab, size, (t_point){current.x + 1, current.y}, target, tofillwith); // Right
    fill(tab, size, (t_point){current.x, current.y - 1}, target, tofillwith); // Up
    fill(tab, size, (t_point){current.x, current.y + 1}, target, tofillwith); // Down
}

void flood_fill(char **tab, t_point size, t_point begin)
{
    char target = tab[begin.y][begin.x]; // The character to be replaced
    char tofillwith = 'F'; // The character to fill with

    // Ensure that the starting point is within bounds
    if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
        return;

    // Perform flood fill
    fill(tab, size, begin, target, tofillwith);
}