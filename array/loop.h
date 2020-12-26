#include "Lap.h"
bool tieptuc()
{
  char ch;
  fflush(stdin);
  printf("\nBan co muon tiep tuc (Y/N):\n");
  scanf("%c", &ch);
  if (toupper(ch) == 'N')
    return false;
  return true;
}
// cosx(float x)
float cosx(float x)
{
  float q = 1, t = 1;
  int k = 2;
  do
  {
    t *= (-1) * x * x / (k * (k - 1));
    q += t;
    k += 2;
  } while (fabs(t) > 0.000001);
  return q;
}
// sinx(float x)
float sinx(float x)
{
  float q = 0, t = x;
  int k = 3;
  do
  {
    q += t;
    t *= (-1) * x * x / (k * (k - 1));
    k += 2;
  } while (fabs(t) > 0.000001);
  return q;
}
// expx(float x)
float expx(float x)
{
  float q = 1, t = 1;
  int k = 1;
  do
  {
    t *= x / k;
    q += t;
    k++;
  } while (fabs(t) > 0.00000001);
  return q;
}
//LNX(X)
float lnx(float x)
{
  if (x <= 0)
    return -1;
  else if (x < 2)
  {
    float q = 0, t = -1;
    int k = 1;
    do
    {
      t *= (-1) * (x - 1);
      q += t / k;
      k++;
    } while ((t / k) < 1000000000 && k < 32767);
    return q;
  }
  else
    return lnx(1 / x);
}