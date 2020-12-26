#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char toantu;
  int giatri;
} Node;
int thutuToantu(char c)
{
  if (c == '*' || c == '/')
    return 2;
  if (c == '+' || c == '-')
    return 1;
  return 0;
}
int isToantu(char c)
{
  if (c == '(' || c == ')' || c == '*' || c == '/' || c == '+' || c == '-')
    return 1;
  return 0;
}
void chuanhoaBieuthuc(char *st)
{
  for (int i = 0; i < strlen(st); i++)
  {
    while (st[i] == ' ')
    {
      for (int j = i; j < strlen(st) - 1; j++)
      {
        st[j] = st[j + 1];
      }
      st[strlen(st) - 1] = '\0';
    }
  }
}
float giatriHauto(Node *node, int n)
{
  float rs = 0;
  int toanhang[n];
  int top = 0;

  for (int i = 0; i < n; i++)
  {
    if (node[i].toantu == '.')
    {
      toanhang[top++] = node[i].giatri;
    }
    else
    {
      if (top < 2)
      {
        printf("Bieuthuc khong hop le!");
        return 0;
      }
      int a = toanhang[--top];
      int b = toanhang[--top];
      switch (node[i].toantu)
      {
      case '+':
        rs = b + a;
        break;
      case '-':
        rs = b - a;
        break;
      case '*':
        rs = b * a;
        break;
      case '/':
        rs = (float)b / a;
        break;
      }
      toanhang[top++] = rs;
    }
  }
  return rs;
}
float giatriBieuthuc(char *tt, char *ht)
{
  char stack[100], num[10], top = 0, m, n = 0;
  Node node[50];
  stack[top] = '$';
  int i = 0;
  while (i < strlen(tt))
  {
    if (isToantu(tt[i]))
    {
      if (thutuToantu(tt[i]) > thutuToantu(stack[top]))
      {
        stack[++top] = tt[i++];
      }
      else
      {
        while (thutuToantu(tt[i]) <= thutuToantu(stack[top]))
        {
          node[n].giatri = -1;
          node[n++].toantu = stack[top--];
        }
        stack[++top] = tt[i++];
      }
    }

    if (isdigit(tt[i]))
    {
      m = -1;
      while ((i < strlen(tt)) && (isdigit(tt[i])))
        num[++m] = tt[i++];
      num[m + 1] = '\0';
      node[n].toantu = '.';
      node[n++].giatri = atoi(num);
    }
    if (tt[i] == '(')
    {
      stack[++top] = tt[i++];
    }
    if (tt[i] == ')')
    {
      while (stack[top] != '(')
      {
        node[n].giatri = -1;
        node[n++].toantu = stack[top--];
      }
      top--;
      i++;
    }
  }
  while (stack[top] != '$')
  {
    node[n].giatri = -1;
    node[n++].toantu = stack[top--];
  }
  ht[0] = '\0';
  for (int i = 0; i < n; i++)
  {
    if (node[i].toantu != '.')
    {
      char s[1];
      s[0] = node[i].toantu;
      s[1] = '\0';
      strcat(ht, s);
    }
    else
    {
      char ss[10];
      ss[0] = '\0';
      sprintf(ss, "%d", node[i].giatri);
      strcat(ht, ss);
    }
    strcat(ht, " ");
  }
  float giatri = giatriHauto(node, n);
  return giatri;
}
int main()
{
  char bieuthuc[50];
  char hauto[50];
  float giatri = 0;
  printf("\nChuong trinh tinh gia tri bieu thuc:");
  printf("\nNhap bieu thuc can tinh: %s", bieuthuc);
  scanf("%s", &bieuthuc);
  chuanhoaBieuthuc(bieuthuc);
  giatri = giatriBsieuthuc(bieuthuc, hauto);
  printf("\nBieu thuc hau to: %s", hauto);
  printf("\nGia tri bieu thuc: %f", giatri);
  system("pause");
  return 0;
}