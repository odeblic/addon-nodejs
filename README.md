# Skeleton of NodeJS addon

This is a basic skeleton of an addon (or plugin) for **NodeJS**.

It comes from from a full application and had to be cleanup (proprietary code), hence the lack of sense in the C++ source: it is just a demo!

The command **node** might have to be replaced by **nodejs** on legacy (**nodejs** is the new **node**).

The tool **node-gyp** allows to Generate Your Project (G.Y.P.) for **NodeJS** which is described in file 'binding.gyp' (like **make** with **Makefile**).

Use the scripts 'build.sh' and 'clean.sh' (**nodejs** and **node-gyp** must be installed first).
