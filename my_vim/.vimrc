call plug#begin('~/.vim/plugged')

Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }
"colorscheme
Plug 'sainnhe/vim-color-desert-night'
"authocompile
"Plug 'ycm-core/YouCompleteMe'
"pairs
Plug 'jiangmiao/auto-pairs'
"Plug 'tpope/vim-fugitive'
"Plug 'airblade/vim-gitgutter'
Plug 'easymotion/vim-easymotion'


call plug#end()
"#slate #pablo #koehler #erflord
syntax on
let g:mapleader='.'
set termguicolors
"colorscheme desert-night
set hlsearch
set background=dark
set number
set tabstop=4 noexpandtab shiftwidth=4

"mappings

map <C-n> :NERDTreeToggle<CR>
map <Leader> <Plug>(easymotion-prefix)
