# If you come from bash you might have to change your $PATH.
# export PATH=$HOME/bin:/usr/local/bin:$PATH

# Path to your oh-my-zsh installation.
export ZSH="/Users/agissing/.oh-my-zsh"

# Set name of the theme to load --- if set to "random", it will
# load a random theme each time oh-my-zsh is loaded, in which case,
# to know which specific one was loaded, run: echo $RANDOM_THEME
# See https://github.com/robbyrussell/oh-my-zsh/wiki/Themes
ZSH_THEME="agnoster"

# Set list of themes to pick from when loading at random
# Setting this variable when ZSH_THEME=random will cause zsh to load
# a theme from this variable instead of looking in ~/.oh-my-zsh/themes/
# If set to an empty array, this variable will have no effect.
# ZSH_THEME_RANDOM_CANDIDATES=( "robbyrussell" "agnoster" )

autoload -U colors && colors
autoload -U compinit && compinit

echo "
   __  ______ ________ _______  __  __              
  /  |/  / _ /_  __/ // /  _/ |/_/ / /____ ______ _ 
 / /|_/ / __ |/ / / _  // /_>  <  / __/ -_) __/  ' \\
/_/  /_/_/ |_/_/ /_//_/___/_/|_|  \\__/\\__/_/ /_/_/_/
                                                    
"
python3 -c "import subprocess; subprocess.Popen(['/bin/zsh', '-c', 'say \"hello mathix\"'])"

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion.
# Case-sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment the following line to disable bi-weekly auto-update checks.
# DISABLE_AUTO_UPDATE="true"

# Uncomment the following line to change how often to auto-update (in days).
export UPDATE_ZSH_DAYS=3

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
# ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# You can set one of the optional three formats:
# "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# or set a custom format using the strftime function format specifications,
# see 'man strftime' for details.
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

export PATH=/Users/agissing/.brew/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:/Library/Frameworks/Mono.framework/Versions/Current/Commands:/usr/local/munki:/tmp/flutter/bin

# Which plugins would you like to load?
# Standard plugins can be found in ~/.oh-my-zsh/plugins/*
# Custom plugins may be added to ~/.oh-my-zsh/custom/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(
  git
)

source $ZSH/oh-my-zsh.sh

# Auto clean
#/bin/rm -rf "$HOME/Library/Caches" ".Trash/*"

# User configuration

# export MANPATH="/usr/local/man:$MANPATH"

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

#less colors

export LESS_TERMCAP_mb=$'\e[1;32m'
export LESS_TERMCAP_md=$'\e[1;32m'
export LESS_TERMCAP_me=$'\e[0m'
export LESS_TERMCAP_se=$'\e[0m'
export LESS_TERMCAP_so=$'\e[01;33m'
export LESS_TERMCAP_ue=$'\e[0m'
export LESS_TERMCAP_us=$'\e[1;4;31m'

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='mvim'
# fi

# Compilation flags
# export ARCHFLAGS="-arch x86_64"

# Load Homebrew config script
# source $HOME/.brewconfig.zsh

# ssh
# export SSH_KEY_PATH="~/.ssh/rsa_id"

export MAIL='agissing@student.42.fr'

# Set personal aliases, overriding those provided by oh-my-zsh libs,
# plugins, and themes. Aliases can be placed here, though oh-my-zsh
# users are encouraged to define aliases within the ZSH_CUSTOM folder.
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"
alias 42FileChecker='bash ~/42FileChecker/42FileChecker.sh'
alias clean="~/42-utilities/cleaner.sh "
alias gff="gcc -Wall -Werror -Wextra "
alias addlibft="cp -r ~/42/ProjetStudent/libft ."
alias check='find . -name "*" -type f | xargs grep -o "\w\+[.]c" | grep -o "\w\+[.]c[:]\w\+[.]c"'
alias sav="~/42-utilities/sav.sh"
alias norm='find . -type f -name "*.c" -or -name "*.h" | xargs norminette | grep "^Error" || echo "\n\e[92mAll files are correctly normed!\n\e[0m"'
alias mf-gen="/bin/sh ~/42-utilities/update.sh; python3 ~/42-utilities/mf-gen.py"
alias proto-list="/bin/sh ~/42-utilities/update.sh; sh ~/42-utilities/proto-list.sh"
alias mamp="open $HOME/MAMP/manager-osx.app"
alias t=tree
