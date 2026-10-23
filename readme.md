# drist

version 3.0.0

*_NOTE_*: This is a heavily modified fork of a fork of the original drist. See the [HISTORY](#history) section below.
This tool is for use with [glm_freebsd_cloud](https://git.sr.ht/~toddg/glm_freebsd_cloud), and as such, makes to promises for other users or use cases.

## BRIEF
drist is a tool to configure and synchronize configurations to, and/or run scrips on remote host(s) via ssh(1).

## DESCRIPTION
Remote host configuration preformed with files and scripts without any special configuration syntaxes/languages, daemons, or agents. drist relies on base tools like sed(1), and ssh(1) and aims at being a simple to use and a pluggable automation tool.

When executed without optional --script-file, --upload-dir, or --upload-file flags, drist will execute the following steps from the current working directory:

1. If folder 'files' or 'files-HOSTNAME'  exists, its content is copied to server.
2. If file 'script' or 'script-HOSTNAME' exists, executed on remote server via ssh(1).

In the previous list, files are copied to or scripts executed on remote server if it's hostname matches 'HOSTNAME' (e.g. a directory called: "files-server.local" would only copy files to a host who's hostname is: "server.local").

If the 'folder' or the 'script' file does not exist, drist will skip it.

drist also supports execution from a different working directory via the use of optional command flags to specify the script or files to be uploaded. See the options and examples sections below.

## OPTIONS

  drist $ drist -h

  v3.0.0
  [-h| -help] [-nk] [-v] [-vv] [-th] [-nc] [-cr] [-ps] [-dc] [-sf] [-ud] [-uf] [-si] [-nd] [-ep [sudo|doas|...]] destination [...]
  -h   | --help                     : display this help message
  -ll  | --log-level                : configure log level [trace|debug|info|warn|error]
  -th  | --truncate-hostname        : truncate hostname
  -nc  | --no-copy-drist-dir        : do NOT copy the temp .drist_XXX dir
  -cr  | --copy-root-dir            : root directory to copy the temp .drist_XXX dir to
  -ps  | --persistent-ssh           : configure ssh connection to be persistent
  -dc  | --delete-copied-files      : delete copied files from the copy root dir when script finishes
  -sf  | --script-file              : script file to run
  -ud  | --upload-dir               : directory to upload to remote server
  -uf  | --upload-file              : file to upload to remote server
  -ni  | --no-invoke                : do NOT invoke the remote script
  -nd  | --no-delete-drist-dir      : do NOT delete remote temp .drist_XXX dir (debugging)
  -ep  | --elevate-permissions      : elevate permissions using [sudo|doas|...]
  -nk  | --no-color-output          : print output without colors


  destination     Specify the remote servers you want drist to work on. The destination can be a file containing a list of hosts, one per line or it can be addresses passed in the command line. If you specify multiples servers, drist will loop over the list respecting the list order.  Note that only one file can be used in the command line.

## PORTABLE, FRICTION-LESS REMOTE DEPLOYS

drist is built for maximum reach: it only needs a POSIX-compatible
/bin/sh, an ssh(1) client and tar(1) on the control system. No heavy
run-times, no daemon to install, no language-specific tool chains — just
the standard Unix tools that are already on most servers. That means
you can push scripts and files to systems (Linux, *BSD, minimal
containers, appliances that include a shell) with one tiny, auditable
script.

- **Minimal requirements:** POSIX sh(1) + ssh(1) + tar(1)
- **No persistent server-side service:** no need to install or run a
  client/server agent.  
- **Fast streaming transfers:** streams files over a single ssh(1)
  connection (reducing IO and latency).
- **Works over plain SSH:** leverages standard ssh(1) semantics and
  optional connection persistence (ControlMaster) when available so
  transfers are secure by default.
- **Streaming file transfer:** tar(1) over ssh(1) keeps transfers
  simple, fast, and compatible with both BSD/GNU tar(1).
- **Auditable & lightweight:** small, readable code you can audit in
  seconds — ideal for ops, incident response, and constrained
  environments.
- **Few dependencies (wide compatibility):** designed to run where
  heavyweight tooling can’t.

Use drist when you want a small, dependable tool that just works with
the ubiquitous Unix tool set.

## BUILD
default install location: /usr/local/bin
```sh
    # make && sudo make install
```


## EXAMPLES
TODO: update examples with the updated params.

## HISTORY
- Originally created by [Solène Rapenne <solene@perso.pw>](https://dataswamp.org/~solene/page-drist-official-website.html)
- Forked by [John Kaul](https://github.com/JohnKaul/drist)
- Note, John's repo is probably what you want to use.
- This repo is heavily modified for use with [glm_freebsd_cloud](https://git.sr.ht/~toddg/glm_freebsd_cloud)
