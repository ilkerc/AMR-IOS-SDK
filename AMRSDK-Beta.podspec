Pod::Spec.new do |s|
	
  s.name             = 'AMRSDK-Beta'
  s.version          = '1.5.5'
  s.source           = {
    :git => 'https://github.com/admost/AMR-IOS-SDK.git',
    :tag => s.version
}
  s.requires_arc     = true
  s.license          = { :type => 'Copyright', :text => <<-LICENSE
									Copyright 2016
									Admost Mediation Limited.
									LICENSE
								}
  s.homepage         = 'http://www.admost.com/'
  s.author           = { 'Admost Mediation Limited' => 'amr@admost.com' }
  s.summary          = 'Admost Mediation Router SDK.'
  s.description      = <<-DESC
Admost Mediation Router is a powerful mediation tool to maximize your ad revenues for your apps and games from all major ad networks.
                       DESC
  s.documentation_url = 'https://admost.github.io/amrios'
  s.platform = :ios
  s.ios.deployment_target = '9.0'
  s.frameworks = 'AdSupport', 'AudioToolbox', 'AVFoundation', 'AVKit', 'CFNetwork', 'CoreGraphics', 'CoreMedia', 'CoreTelephony', 'JavaScriptCore', 'MediaPlayer', 'QuartzCore', 'SafariServices', 'SystemConfiguration'
  s.weak_frameworks = ['Foundation', 'UIKit', 'WebKit', 'StoreKit']
  s.libraries = 'sqlite3', 'z'
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-ObjC -lc++' }
  s.source_files = 'AMRSDK/AMRSDK.framework/Headers/*.h'
  s.public_header_files = 'AMRSDK-Beta/AMRSDK.framework/Headers/*.h'
  s.vendored_frameworks = 'AMRSDK-Beta/AMRSDK.framework'
  s.resources = ['AMRSDK-Beta/AMRResources.bundle']
  s.dependency 'KokteylLog', '~> 1.0.8'
end
