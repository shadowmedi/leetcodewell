#define _CRT_SECURE_NO_WARNINGS
bool oneEditAway(char* first, char* second)
{
    int tran = 0;
    int firlen = strlen(first);
    int seclen = strlen(second);
    if (fabs(firlen - seclen) > 1)
        return false;
    int pf = 0;
    int sf = 0;
    if (firlen == seclen)
    {
        for (pf = 0, sf = 0; pf < firlen; pf++, sf++)
        {
            if (first[pf] != second[sf])
            {
                tran++;
            }
        }
        if (tran <= 1)
            return true;
        else
            return false;
    }
    else if (firlen > seclen)
    {
        while (pf < firlen)
        {
            if (first[pf] == second[sf])
            {
                pf++;
                sf++;
            }
            else
            {
                pf++;
                tran++;
            }
        }
        if (tran == 1)
            return true;
        else
            return false;
    }
    else
    {
        while (sf < seclen)
        {
            if (first[pf] == second[sf])
            {
                pf++;
                sf++;
            }
            else
            {
                sf++;
                tran++;
            }
        }
        if (tran == 1)
            return true;
        else
            return false;
    }
    return false;
}