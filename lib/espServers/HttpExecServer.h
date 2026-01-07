#ifndef HttpExecServer_h
#define HttpExecServer_h

#include "HttpServer.h"

class YRShellExec;

class HttpExecServer : public HttpServer {
protected:
  YRShellExec* m_shell;
  char m_auxBuf[ 128];
  uint8_t m_auxBufIndex;

  bool m_lastPromptEnable, m_lastCommandEcho;

  virtual void exec( const char *p);
  virtual void startExec( void);
  virtual void endExec( void);
  virtual bool sendExecReply( void);

public:
  HttpExecServer( ) { m_shell = nullptr; }
  virtual ~HttpExecServer() {}
  virtual const char* sliceName( ) { return "HttpExecServer"; }
  void setYRShell( YRShellExec* s) { m_shell = s; }
};

#endif