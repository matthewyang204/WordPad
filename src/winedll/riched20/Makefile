MODULE=riched20.dll
IMPORTLIB=riched20.lib

CC=cl
RC=rc
LINK=link

CFLAGS=/nologo /W3 /O2 /MD /DWIN32_LEAN_AND_MEAN /D_X86_
LDFLAGS=/DLL /NOLOGO /SUBSYSTEM:WINDOWS /MACHINE:X86 /BASE:0x7ac00000

IMPORTS=uuid.lib ole32.lib oleaut32.lib imm32.lib user32.lib gdi32.lib

SOURCES=caret.c clipboard.c context.c editor.c list.c paint.c para.c reader.c richole.c row.c run.c string.c style.c table.c txthost.c txtsrv.c undo.c wrap.c writer.c

OBJECTS=caret.obj clipboard.obj context.obj editor.obj list.obj paint.obj para.obj reader.obj richole.obj row.obj run.obj string.obj style.obj table.obj txthost.obj txtsrv.obj undo.obj wrap.obj writer.obj

all: $(MODULE)

$(MODULE): $(OBJECTS) rsrc.res
	$(LINK) $(LDFLAGS) /OUT:$(MODULE) $(OBJECTS) rsrc.res $(IMPORTS)

.c.obj:
	$(CC) $(CFLAGS) /c $< /Fo$@

rsrc.res: rsrc.rc
	$(RC) /nologo /fo $@ $<

clean:
	del /Q $(OBJECTS) rsrc.res $(MODULE) $(IMPORTLIB) 2>NUL
