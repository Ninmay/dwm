#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

PS1='\[\033[1;31m\][\u@\h \[\033[1;37m\]\W\[\033[1;31m\]]\$ \[\033[0;37m\]'
# Add to path
export PATH=/home/nintendo/.local/bin:$PATH

# modes
alias music='mpv ~/Music/* --shuffle'

# applications
alias ls='ls --color=auto --group-directories-first'
alias fcd='cd $(find ~ -not -path "*/.*" -type d -print | fzf)'
alias fhcd='cd $(find ~ -type d -print | fzf)'
alias frun='source frun'
alias fr='source fr'

alias tree='watch -n 5 tree . -L 1'
alias ranger='. ranger'
alias youtube-dl='youtube-dl --no-playlist --audio-format mp3 --audio-quality 320K'

# short
alias m='udisksctl mount -b'
alias um='udisksctl unmount -b'

# coding
alias mkjmain='cp ~/.vim/completion/Main.java .'
alias cleantags='rm tags *.taghl'

if [ -z "$DISPLAY" ] && [ "$(fgconsole)" -eq 1 ]; then
  exec startx
fi
