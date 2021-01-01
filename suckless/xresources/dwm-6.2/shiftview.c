void
shiftview(const Arg *arg) {
        Arg shifted;

        if(arg->i > 0) // left circular shift
                shifted.ui = (selmon->tagset[selmon->seltags] << arg->i)
                   | (selmon->tagset[selmon->seltags] >> (LENGTH(tags) - arg->i));

        else // right circular shift
                shifted.ui = selmon->tagset[selmon->seltags] >> (- arg->i)
                   | selmon->tagset[selmon->seltags] << (LENGTH(tags) + arg->i);

        view(&shifted);
}

