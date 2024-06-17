//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.10
//
// <auto-generated>
//
// Generated from file `LocalException.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

package com.zeroc.Ice;

/** This exception is raised when a failure occurs during initialization. */
public class InitializationException extends LocalException {
  public InitializationException() {
    this.reason = "";
  }

  public InitializationException(Throwable cause) {
    super(cause);
    this.reason = "";
  }

  public InitializationException(String reason) {
    this.reason = reason;
  }

  public InitializationException(String reason, Throwable cause) {
    super(cause);
    this.reason = reason;
  }

  public String ice_id() {
    return "::Ice::InitializationException";
  }

  /** The reason for the failure. */
  public String reason;

  private static final long serialVersionUID = 578611869232039264L;
}
