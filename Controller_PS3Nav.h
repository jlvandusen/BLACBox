/* =================================================================================
 *    B.L.A.C.Box: Brian Lubkeman's Astromech Controller
 * =================================================================================
 * Controller_PS3Nav.h - Library for the subclass for the PS3 Move Navigation controller
 * Created by Brian Lubkeman, 22 November 2020
 * Inspired by S.H.A.D.O.W. controller code written by KnightShade
 * Released into the public domain.
 */
#ifndef _CONTROLLER_PS3NAV_H_
#define _CONTROLLER_PS3NAV_H_

#include "Buffer.h"
#include "Controller_All.h"
#include <PS3BT.h>

extern String output;
extern void printOutput(void);

// PS3 Move Navigation controller priorities

const uint8_t FIRST = 0;
const uint8_t SECOND = 1;


/* ===========================================================
 * This is a test subclass for specifice controller system.
 * =========================================================== */
class Controller_PS3Nav : public Controller_Parent
{
  public:
    Controller_PS3Nav(Buffer *);
    void begin(void);
    bool read(void);

  // For use by attachOnInit
    static Controller_PS3Nav * Controller_PS3Nav::anchor;

  private:
    PS3BT _controller;
    PS3BT _secondController;
    virtual void _connect(PS3BT *);
    virtual void _disconnect(PS3BT *);

  // onAttachInit functions
    static void _onInit(void);
    virtual void _onInitConnect(void);

  // Critical fault detection variable and functions
    CriticalFault_Struct _faultData;
    CriticalFault_Struct _secondFaultData;
    virtual void _initCriticalFault(CriticalFault_Struct *);
    virtual bool _detectCriticalFault(CriticalFault_Struct *);
    virtual void _resetCriticalFault(CriticalFault_Struct *);

  // Buffer functions
    void _setBuffer(void);
    void _updateBuffer(void);
    void _crazyIvan(uint8_t, uint8_t, uint8_t);
};
#endif    // _CONTROLLER_PS3NAV_H_
