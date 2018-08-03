syntax on
set cindent
set nu
set tabstop=4
set shiftwidth=4
set background=dark
set mouse=a

map<C-A> ggvG"+y
map<F5> :call Run()<CR>

func! Run()
    exec "w"
    exec "!g++ -std=c++11 -O2 % -o %<"
    exec "!time ./%<"
endfunc

autocmd BufNewFile *.cpp 0r ~/include.cpp
autocmd BufNewFile *.cpp normal G

inoremap ( ()<Esc>i
inoremap [ []<Esc>i
inoremap { {<CR>}<Esc>O
inoremap ' ''<Esc>i
inoremap " ""<Esc>i

inoremap ) <c-r>=ClosePair(')')<CR>
inoremap ] <c-r>=ClosePair(']')<CR>

func ClosePair(char)
	if getline('.')[col('.')-1]==a:char
		return "\<Right>"
	else
		return a:char
	endif
endfunc
